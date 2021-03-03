

const get = (url) => {
    return new Promise((resolve, reject) => {
        let xhr = new XMLHttpRequest()

        xhr.onreadystatechange = _ => {
            if (xhr.readyState == 4) {
                if (xhr.status == 200)
                    resolve(xhr.responseText)
                else
                    reject(xhr)
            }
        }
        xhr.open('GET', url, true)
        xhr.send()
    })
}

const catchError = e => console.error('Ajax Error:', e)

const getPosts = _ => {
    return get('https://jsonplaceholder.typicode.com/users').then(response => {
        let users = JSON.parse(response)
        return get('https://jsonplaceholder.typicode.com/comments?userId=' + users[0].id)
    }).then(response => {
        let posts = JSON.parse(response)
        return posts
    })
}


getPosts().then(posts => console.log(posts[0])).catch(e => console.error('Ajax Error: ', e))