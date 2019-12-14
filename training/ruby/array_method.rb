# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    array_method.rb                                  .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/14 18:49:53 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/14 20:07:45 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

def accessing_elem(days)
	puts days[0], days[-1], days.first, days.last, days.fetch(42, "Nope")
end

def accessing_multi_elems(days)
	puts days[1, days.index(days.last)], "\n", days.reverse.take(5)
end

def random_entry(days, nb)
	puts days.sample, nb
end

def find_elem(days)
	puts days.include? "Monday"
	puts days.find {|day| day.include? "a"}
	print days.select {|day| day.include? "e"}, "\n"
	print days.reject {|day| day.include? "e"}, "\n"
end

def sort_elem(nbs, days, hash)
	print nbs.sort, "\n"
	print days.sort{|a, b| a <=> b}, "\n"
	print days.sort{|a, b| b <=> a}, "\n"
	print hash.sort{|a, b| a[:value] <=> b[:value]}, "\n"
	print hash.sort_by{|a| a[:value]}, "\n" # optimized for complex data set
	print hash.uniq.sort_by{|a| a[:value]}, "\n"
	print hash + days, "\n"
	print hash | days, "\n" # concatenate + uniq method
end

def apply_action(nbs, days)
	print nbs.map{|nb| nb ** 2}, "\n"
	print days.map{|day| "<option>#{day}</option>"}, "\n"
	puts days.join(", ")
	print days.map{|day| "<option>#{day}</option>"}.join("\n"), "\n"
	puts nbs.reduce{|result, current| result += current}
	puts nbs.reduce(5){|result, current| result += current}
	puts nbs.reduce(:+)
	days.join(" ").split.each{|day| puts day}
end

days = %w{Monday Tuesday Wednesday Thursday Friday Saturday Sunday}
nbs = [1000, -5, 8, 98, 789, -654.45, 78.45678]
=begin
##hash = [
	{value: 894},
	{value: 13},
	{value: -4585},
	{value: 13},
	{value: 11},
	{value: 12},
]
=end

#accessing_elem days
#accessing_multi_elems days
#random_entry days, 7
#find_elem days
#sort_elem(nbs, days, hash)
apply_action(nbs, days)
