# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    composition.rb                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/13 19:20:15 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/13 19:53:33 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

class Student
	attr_accessor :name, :exams

	def initialize(name)
		@name = name
	end

	def print_grade
		puts "#{name}'s exam :\n"
		exams.each do |exam|
			puts "#{exam.name} -> #{exam.grade}\n"
		end
	end

	def average
		total = 0
		exams.each do |exam|
			total += exam.grade
		end
		total / exams.size
	end
end

class Exam
	attr_accessor :name, :grade

	def initialize(name, grade)
		@name = name
		@grade = grade
	end
end

billy = Student.new("Billy")

math = Exam.new("maths", 10.5)
philo = Exam.new("philo", 14)

billy.exams = [math, philo]
billy.print_grade
puts "#{billy.name}'s average is #{billy.average}"

