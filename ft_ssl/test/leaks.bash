#valgrind --leak-check=full --show-leak-kinds=all
echo -n "" | valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./ft_ssl des-ecb -p "" -s 0 -a
#echo -n "0123456789" | ./ft_ssl des-ecb -p "" -s 0 -a

#echo -n "" | valgrind --leak-check=full --show-leak-kinds=all ./ft_ssl des-ecb -p "" -s 0 -a
#
#echo -n "0123456789" | valgrind --leak-check=full --show-leak-kinds=all ./ft_ssl des-ecb -p "" -s 0 -a
#
#echo "U2FsdGVkX18AAAAAAAAAALIzZ9k1UU1m" | valgrind --leak-check=full --show-leak-kinds=all ./ft_ssl des-ecb -p "" -a -d
#
#echo "UFsdGVkX18AAAAAAAAAALIzZ9k1U" | valgrind --leak-check=full --show-leak-kinds=all ./ft_ssl des-ecb -p "" -a -d
#
#echo "U2FsdGVkX18AAAAAAAAAAGeLhWVM1djllTlJEvnilZY=" | valgrind --leak-check=full --show-leak-kinds=all ./ft_ssl des-ecb -p "" -a -d
#
#echo "U2FsdGVkX19IiEMkP
#7
#/32eW2xH
#JxDMbTrFN3/M
#kYOa4=" | openssl des -pass "pass:coucou" -S 488843243FBFF7D9 -a -d
#echo "U2FsdGVkX19IiEMkP7/32eW2xHJxDMbTrFN3/MkYOa4=" | valgrind --leak-check=full --show-leak-kinds=all ./ft_ssl des -p "coucou" -s 488840000FBFF7D9 -a -d
#
#echo "U2FsdGVkX18AAAAAAAAAAGeLhWVM1djllT" | valgrind --leak-check=full --show-leak-kinds=all ./ft_ssl des-ecb -p "m" -a -d
#