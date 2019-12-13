# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    inheritance.rb                                   .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/13 17:28:51 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/13 19:19:56 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

class Animal
	attr_accessor :name

	def initialize(name)
		@name = name
	end
end

class Cat < Animal
	def present
		puts "#{name}: Miaou"
	end
end

class Dog < Animal
	def present
		puts "#{name}: Wouaf"
	end
end

rex = Dog.new("Rex")
busto = Cat.new("Busto")

rex.present
busto.present
