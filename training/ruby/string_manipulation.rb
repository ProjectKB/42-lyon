# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    string_manipulation.rb                           .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/13 20:58:17 by loiberti     #+#   ##    ##    #+#        #
#    Updated: 2019/12/14 18:12:19 by loiberti    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

def basic_feature(str)
	puts str + " " + str
	puts str * 3
	puts "1" + "2"
	puts "1" * 2
	puts str.size
	puts str.length
	puts str.capitalize
	puts str.reverse
	puts str.upcase
	puts str.downcase
	puts str.swapcase
end

def basic_info(str)
	puts str.is_a?(Integer)
	puts str.is_a?(Float)
	puts str.is_a?(String)
	puts str.to_i
	puts str.to_f
end

def basic_cut(str)
	puts str[0]
	puts str[1,2]
	puts str[1..4]
end

def padding_stripping(str)
	puts str.center(21)
	puts str.center(21, "<>")
	puts str.ljust(20)
	puts str.rjust(20)
	puts str.rjust(20, "<>")
	puts str.center(21).strip
	puts str.chop
	puts str.chomp("cOu") # just chomp will erase nl if nl exist
end

def finding_char(str)
	puts str.include?("W")
	puts str.index("W")
	puts str.index("Wor")
	puts str.start_with?("Hello")
	puts str.end_with?("World!")

	text = "Sammy has a balloon"
	indices = text.chars
		.each_with_index
		.select{|char, index| char == "a" }
		.map{|pair| pair.last}
	print indices, "\n"
end

def replace_text(str)
	str.sub!("C", "H").gsub!(/o/, "*") # '!' modify str like a pointer | sub/gsub accept regex
	puts str
end



#basic_feature("coucOu")
#basic_info("coucOu")
#basic_cut("coucOu")
#padding_stripping("coucOu")
#finding_char("Hello World!")
replace_text("Cello Wooooooooorld!")
