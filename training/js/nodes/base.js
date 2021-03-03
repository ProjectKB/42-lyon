let http = require('http')
let fs = require('fs')
let url = require('url')

http.createServer((request, response) => {

    let query = url.parse(request.url, true).query
    let name  = query.name == undefined ? 'anonyme' : query.name

    fs.readFile('index.html', 'utf8', (err, data) => {
        if (err) {
            response.writeHead(404)
            response.end('Ce fichier n\'existe pas')
        } else {
            response.writeHead(200, {
                'Content-type': 'text/html'
            })
            
            data = data.replace('{{ name }}', name)
            response.end(data)
        }
    });

}).listen(8080)
