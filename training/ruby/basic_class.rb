# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    user.rb                                          .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/13 16:43:58 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/13 17:03:59 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

class User
	attr_accessor :firstname, :lastname, :country

	def fullname
		firstname + " " + lastname
	end

	def lived_in(v)
		v == country
	end
end

bob = User.new
bob.firstname = "Bob"
bob.lastname = "Lennon"
bob.country = "France"

puts bob.fullname
puts bob.lived_in("France")
