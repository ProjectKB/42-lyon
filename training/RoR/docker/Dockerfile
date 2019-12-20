FROM ruby:2.3.7
RUN apt-get update -qq apt-get install -y build-essential libpq-dev nodejs
RUN mkdir /one
WORKDIR /one
ADD Gemfile /one/Gemfile
ADD Gemfile.lock /one/Gemfile.lock
ADD . /one
