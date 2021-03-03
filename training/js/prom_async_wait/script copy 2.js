

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

// async method always return a promise
// to use 'await' we have to be in async functions
const getPosts = async _ => {
    let response = await get('https://jsonplaceholder.typicode.com/users')
    let users = JSON.parse(response)
    response = await get(`https://jsonplaceholder.typicode.com/comments?userId=${users[0].id}`)
    let posts = JSON.parse(response)
    return posts
}

const getFirstPost = async _ => {
    let posts = await getPosts()
    return posts[0]
}

const demo = async _ => {
    let arr = await Promise.all([getPosts(), getFirstPost()])
    return arr
}

demo().then(response => console.log(response)).catch(error => console.error(`Ajax Error: ${error}`))