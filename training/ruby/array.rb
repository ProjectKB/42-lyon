# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    array.rb                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/14 17:57:43 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/14 18:34:41 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

def array_declaration
	days = %w{Monday Tuesday Wednesday Thursday Friday Saturday Sunday} # is equivalent to
	days2 = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]

	print days, days2, "\n"
	print days.first, days.last, "\n"
end

def add_elem
	days.push("Moonday") # is equivalent to
	days << ("Saturnday")
	puts days[-1], days[-2] # index from the end

	days.unshift("Mercuryday")
	puts days[0]
end

def delete_elem
	test = [1, 2, 3, 4, 10, 6, 7, 8, 9, 10]
	test2 = [1, 2, 3, 4, 10, 6, 7, 8, 9, 10]
	while (a = test.index(10)) != nil do
		test.delete_at(a)
	end

	test2.delete(10)
	puts test, test2
	puts "coucou".delete('c') # very useful to erase all occur for first/last occur use .index/.rindex
end

def delete_elem2
	sharks = ["Hammerhead", "Great White", "Tiger", "Whale"]
	deleted_at_element = sharks.delete_at(1)
	popped_element = sharks.pop

	puts "Deleted_at element: #{deleted_at_element}"
	puts "Popped element: #{popped_element}"
	puts "Remaining array: #{sharks}"
end

#array_declaration
#add_elem
#delete_elem
#delete_elem2
