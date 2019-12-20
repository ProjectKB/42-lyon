Rails.application.routes.draw do
  root 'books#index'

  post '/' => 'books#create'
  patch '/:id' => 'books#update'
  get '/:id' => 'books#show'
  delete '/:id' => 'books#delete'

  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
end
