# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    basic_class2.rb                                  .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/13 17:04:21 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/13 17:28:41 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

class User
	attr_accessor :name, :friends

	def initialize(name)
		@name = name
	end

	def is_friend_with(name)
		friends.each do |friend|
			return true if friend.name == name
		end
		return false
	end
end

alice = User.new("Alice")
bob = User.new("Bob")
jane = User.new("Jane")

alice.friends = [bob]
alice.friends << jane

puts alice.friends.size
puts alice.is_friend_with("Jane")
puts alice.is_friend_with("Marco")
