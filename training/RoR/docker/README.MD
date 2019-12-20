Create app :
docker-compose run web rails new . --force --database=postgresql --skip-bundle

Add to db (config/database.yml) up to development :
default: &default
	( adapter: postgresql
	  encoding: unicode
	  pool: 5 )
	username: postgres
	password:
	host: db

Launch server :
docker-compose up

If you have issue or you change your Gemfile/Dockerfile
docker-compose build

Create db:
dc-web rake db:create

Before every rails command use :
docker-compose run web -> alias
