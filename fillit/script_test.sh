GREEN='\033[0;32m'
WHITE='\033[0;29m'
ORANGE='\033[1;33m'

make re GRAPHIC=yes

	printf "\t\033[1;33m ======CHECK_ERRORS======\n$WHITE\n"


printf "$GREEN invalid_no_arg\n\t$WHITE"
./fillit
printf "$GREEN invalid_2_arg$WHITE\n\t"
./fillit MAPS/invalid_last_line MAPS/invalid_no_newline
printf "$GREEN invalid_fucked_arg$WHITE\n\t"
./fillit sgshgdthbxbdrsg
printf "$GREEN invalid_folder$WHITE\n\t"
./fillit MAPS
printf "$GREEN invalid_file_with_no_rights$WHITE\n\t"
chmod 000 MAPS/invalid_line
./fillit MAPS/invalid_line
chmod 644 MAPS/invalid_line
printf "$GREEN invalid_27_pieces$WHITE\n\t"
./fillit MAPS/invalid_27_pieces
printf  "$GREEN invalid_last_line$WHITE\n\t"
./fillit MAPS/invalid_last_line
printf "$GREEN invalid_last_line_2$WHITE\n\t"
./fillit MAPS/invalid_last_line_2
printf "$GREEN invalid_char$WHITE\n\t"
./fillit MAPS/invalid_char
printf "$GREEN invalid_char_2$WHITE\n\t"
./fillit MAPS/invalid_char_2
printf "$GREEN invalid_char3$WHITE\n\t"
./fillit MAPS/invalid_char3
printf "$GREEN invalid_line$WHITE\n\t"
./fillit MAPS/invalid_line
printf "$GREEN invalid_nb_lines$WHITE\n\t"
./fillit MAPS/invalid_nb_lines
printf "$GREEN invalid_nl_end$WHITE\n\t"
./fillit MAPS/invalid_nl_end
printf "$GREEN invalid_no_newline$WHITE\n\t"
./fillit MAPS/invalid_no_newline
printf "$GREEN invalid_two_newlines$WHITE\n\t"
./fillit MAPS/invalid_two_newlines
printf "$GREEN invalid_tetrimino$WHITE\n\t"
./fillit MAPS/invalid_tetrimino
printf "$GREEN invalid_tetrimino_2$WHITE\n\t"
./fillit MAPS/invalid_tetrimino_2
printf "$GREEN invalid_tetrimino_3$WHITE\n\t"
./fillit MAPS/invalid_tetrimino_3
printf "$GREEN invalid_empty_tetrimino$WHITE\n\t"
./fillit MAPS/invalid_empty_tetrimino
printf "$GREEN invalid_empty$WHITE\n\t"
./fillit MAPS/invalid_empty
printf "$GREEN invalid_bullshit$WHITE\n\t"
./fillit MAPS/invalid_bullshit
printf "$GREEN invalid_mjalenqu$WHITE\n\t"
./fillit MAPS/invalid_mjalenqu
printf "\t\033[1;33m ======CHECK_VALIDS======\n$WHITE\n"
 printf "$GREEN valid_1$WHITE\n"
 ./fillit MAPS/valid_1
 printf "$GREEN valid_2$WHITE\n"
 ./fillit MAPS/valid_2
 printf "$GREEN valid_3$WHITE\n"
 ./fillit MAPS/valid_3
 printf "$GREEN valid_4$WHITE\n"
 ./fillit MAPS/valid_4
printf "$GREEN valid_5$WHITE\n"
./fillit MAPS/valid_5
printf "$GREEN valid_6$WHITE\n"
./fillit MAPS/valid_6
