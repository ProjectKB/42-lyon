class BooksController < ApplicationController
  def index
    @books = Book.all
    @categories = Category.all
  end

  def create
    Book.create title: params[:title], category_id: params[:category]
    redirect_to '/'
  end

  def show
    @book = Book.find(params[:id])
    @categories = Category.all
  end

  def update
    @to_update = Book.find(params[:id])
    @to_update.update title: params[:title]
    @to_update.update category_id: params[:category]
    redirect_to "/#{params[:id]}"
  end

  def delete
    Book.find(params[:id]).destroy
    redirect_to "/"
  end
end
