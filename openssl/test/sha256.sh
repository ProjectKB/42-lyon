./ft_ssl sha256 ./test/empty
cat ./test/empty | ./ft_ssl sha256
openssl sha256 ./test/empty
echo ""
./ft_ssl sha256 ./test/less_than_56
cat ./test/less_than_56 | ./ft_ssl sha256
openssl sha256 ./test/less_than_56
echo ""
./ft_ssl sha256 ./test/more_than_64
cat ./test/more_than_64 | ./ft_ssl sha256
openssl sha256 ./test/more_than_64
echo ""
./ft_ssl sha256 ./test/between_56_\&_64
cat ./test/between_56_\&_64 | ./ft_ssl sha256
openssl sha256 ./test/between_56_\&_64
echo ""
./ft_ssl sha256 ./test/big
cat ./test/big | ./ft_ssl sha256
openssl sha256 ./test/big