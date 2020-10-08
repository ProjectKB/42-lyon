./ft_ssl ./test/empty
cat ./test/empty | ./ft_ssl
openssl md5 ./test/empty
echo ""
./ft_ssl ./test/less_than_56
cat ./test/less_than_56 | ./ft_ssl
openssl md5 ./test/less_than_56
echo ""
./ft_ssl ./test/more_than_64
cat ./test/more_than_64 | ./ft_ssl
openssl md5 ./test/more_than_64
echo ""
./ft_ssl ./test/between_56_\&_64
cat ./test/between_56_\&_64 | ./ft_ssl
openssl md5 ./test/between_56_\&_64
echo ""
./ft_ssl ./test/big
cat ./test/big | ./ft_ssl
openssl md5 ./test/big