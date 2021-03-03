const get = async url => {
    try {
        let response = await fetch(url)
        if (response.ok) {
            let data = await response.json()
            return data
        } else
            throw `Status is: ${response.status}`
    } catch (e) {
        throw e
    }
}

const getPosts = async _ => {
    try {
        let users = await get('https://jsonplaceholder.typicode.com/users')
        let posts = await get(`https://jsonplaceholder.typicode.com/comments?userId=${users[0].id}`)
        console.log(posts[0])
    } catch (e) {
        console.error(e)
    }
}

getPosts()