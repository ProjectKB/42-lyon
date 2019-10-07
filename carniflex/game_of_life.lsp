(ql:quickload :lispbuilder-sdl)

(setq is_play 0)
(setq width 1000)
(setq height 1000)
(setq collumns 50)
(setq lines 50)
(setq step_y (/ height lines))
(setq step_x (/ width collumns))
(setq my_time 0)
(setq x_translation 0)
(setq y_translation 0)
(setq zoom 1)
(setq fps 500)
(setq drag 0)
(setq drag_x 0)
(setq drag_y 0)
(defparameter *my-array* (make-array (list lines collumns) :initial-element 0))

(sb-int:with-float-traps-masked (:invalid :inexact :overflow)

(defun draw_case (y x)
    (let ((r_x (* (+ (* x step_x) x_translation) zoom))
    (r_y (* (+ (* y step_y) y_translation) zoom)))
    (sdl:draw-box (sdl:rectangle-from-edges-* r_x r_y (+ r_x (* step_x zoom)) (+ r_y (* step_y zoom)))
    :color (sdl:color :r 100 :b 150 :g 250))))

(defun update_screen ()
    (sdl:clear-display (sdl:color))
    (loop for i from 0 to (- lines 1) by 1 do ;;saver
        (loop for j from 0 to (- collumns 1) by 1 do
            (if (= (aref *my-array* i j) 1) 
                (draw_case i j))))
    (sdl:update-display))

(defun reset_frame ()
    (setq is_play 0)
    (setq zoom 1)
    (setq x_translation 0)
    (setq y_translation 0)
    (sdl:clear-display (sdl:color))
    (loop for i from 0 to (- lines 1) by 1 do ;;saver
        (loop for j from 0 to (- collumns 1) by 1 do
            (setf (aref *my-array* i j) 0)))
    (sdl:update-display))

(defun count_neighboor (y x)
    (setq y_start (if (< (- y 1) 0) 0 (- y 1)))
    (setq x_start (if (< (- x 1) 0) 0 (- x 1)))
    (setq y_end (if (> (+ y 1) (- lines 1)) (- lines 1) (+ y 1)))
    (setq x_end (if (> (+ x 1) (- collumns 1)) (- collumns 1) (+ x 1)))
    (setq neighboor 0)
    (loop for i from y_start to y_end by 1 do
        (loop for j from x_start to x_end by 1 do
            (if (and (or (/= i y) (/= j x)) (or (= (aref *my-array* i j) 1) (= (aref *my-array* i j) 3)))
                (incf neighboor 1))))
    (return-from count_neighboor neighboor))

(defun next_frame ()
    (if (and (= is_play 1)(> (get-internal-real-time) (+ my_time fps)))
    (progn
        (setq my_time (get-internal-real-time))
        (loop for i from 0 to (- lines 1) by 1 do ;;editer
            (loop for j from 0 to (- collumns 1) by 1 do
                (if (and (= (aref *my-array* i j) 1) (< (count_neighboor i j) 2))
                    (setf (aref *my-array* i j) 3)
                    (if (and (= (aref *my-array* i j) 1) (> (count_neighboor i j) 3))
                        (setf (aref *my-array* i j) 3)
                        (if (and (= (aref *my-array* i j) 0) (= (count_neighboor i j) 3))
                            (setf (aref *my-array* i j) 2))))))
        (loop for i from 0 to (- lines 1) by 1 do ;;saver
            (loop for j from 0 to (- collumns 1) by 1 do
                (if (= (aref *my-array* i j) 3)
                    (setf (aref *my-array* i j) 0)
                    (if (= (aref *my-array* i j) 2)
                        (setf (aref *my-array* i j) 1)))))))
        (update_screen))

(defun usage ()
  (let ((banner "~%usage: sbcl --load game_of_life.lsp [-h] width height
positional arguments:
  width                 width of the grid
  height                height of the grid
optional arguments:
  -h, --help            show this help message and exit~%~%"))
	(if (or (loop for arg in *posix-argv*
				  when (or (string-equal "-h" arg)
						   (string-equal "--help" arg))
				  return t)
			(not (< 2 (length *posix-argv*))) (> (length *posix-argv*) 3))
		(progn
		  (format t banner)
		  (quit))))
	'continue)

(defun main(argv)
    (usage)
    (defparameter *width* (parse-integer (second argv)))
    (defparameter *height* (parse-integer (third argv)))
    (if (or (> *width* 2000) (> *height* 2000))
	  (progn
		(format t "~%usage : width and/or height can't exceed 2000.~%~%")
		(quit)))
    (if (or (< *width* 0) (< *height* 0))
	  (progn
		(format t "~%usage : width and/or height can't be negative.~%~%")
		(quit)))
    (sdl:with-init ()
  
      (sdl:window *width* *height*)
      (sdl:enable-key-repeat 10 10)
      (sdl:update-display)
      (sdl:with-events ()
          (:quit-event () (quit))
          (:key-down-event ()
              (when (sdl:key-down-p :sdl-key-escape)
                  (quit))
              (when (sdl:key-down-p :sdl-key-p)
                  (setq is_play (if (= is_play 1) 0 1)))
              (when (sdl:key-down-p :sdl-key-w)
                  (decf y_translation (/ 20 zoom))
                  (next_frame))
              (when (sdl:key-down-p :sdl-key-s)
                  (incf y_translation (/ 20 zoom))
                  (next_frame))
              (when (sdl:key-down-p :sdl-key-a)
                  (decf x_translation (/ 20 zoom))
                  (next_frame))
              (when (sdl:key-down-p :sdl-key-d)
                  (incf x_translation (/ 20 zoom))
                  (next_frame))
              (when (sdl:key-down-p :sdl-key-kp-plus)
                  (setq zoom (* zoom 1.15))
                  (next_frame))
              (when (sdl:key-down-p :sdl-key-kp-minus)
                  (setq zoom (* zoom 0.85))
                  (next_frame))
              (when (sdl:key-down-p :sdl-key-r)
                  (reset_frame))
              (when (sdl:key-down-p :sdl-key-comma) ;;less
                  (incf fps 50)
                  (setq fps (if (> fps 2000) 2000 fps)))
              (when (sdl:key-down-p :sdl-key-period) ;;greater
                  (decf fps 50)
                  (setq fps (if (< fps 0) 0 fps))))
          (:mouse-button-down-event (:button button :X mouse-x :Y mouse-y)
                (when (sdl:mouse-left-p)
                    (setq drag 1)
                    (setq drag_x mouse-x)
                    (setq drag_y mouse-y))
              (when (sdl:mouse-right-p)
                  (let ((s_x (floor(/ (- (/ mouse-x zoom) x_translation) step_x)))
                      (s_y (floor(/ (- (/ mouse-y zoom) y_translation) step_y))))
                      (if (and (and (< s_x collumns) (< s_y lines)) (and (>= s_x 0) (>= s_y 0)))
                      (progn
                          (setf (aref *my-array* s_y s_x) (if (= (aref *my-array* s_y s_x) 0) 1 0))
                          (update_screen))))
                  (sdl:update-display))
              (when (= button 4)
                  (if (sdl:key-down-p (or :sdl-key-lctrl :sdl-key-rctrl))
                      (progn
                          (incf fps 50)
                          (setq fps (if (> fps 2000) 2000 fps)))
                      (progn
                          (setq zoom (* zoom 1.15))
                          (next_frame))))
              (when (= button 5)
                  (if (sdl:key-down-p (or :sdl-key-lctrl :sdl-key-rctrl))
                      (progn
                          (decf fps 50)
                          (setq fps (if (< fps 0) 0 fps)))
                      (progn
                          (setq zoom (* zoom 0.85))
                          (next_frame)))))
            (:mouse-button-up-event (:button button :X mouse-x :Y mouse-y)
                (when (= button 1)
                    (setq drag 0)
                    (setq drag_x 0)
                    (setq drag_y 0)))
            (:mouse-motion-event (:X mouse-x :Y mouse-y)
                (when (= drag 1)
                    (incf x_translation (- (/ mouse-x zoom) (/ drag_x zoom)))
                    (incf y_translation (- (/ mouse-y zoom) (/ drag_y zoom)))
                    (setq drag_x mouse-x)
                    (setq drag_y mouse-y)
                    (next_frame)))
          (:idle () ;;LOOP              
              (next_frame))))))
(sb-int:with-float-traps-masked (:invalid :inexact :overflow) (main *posix-argv*))