const getUsers = async _ => {
    try {
        let response = await fetch('https://jsonplaceholder.typicode.com/users')
        if (response.ok) {
            let data = await response.json()
            console.log(data)
        } else
            console.error(`Ajax Error: ${response.status}`)
    } catch (e) {
        console.error(`Fetch Error: ${e}`)
    }
}

const insertPost = async data => {
    let response = await fetch('https://jsonplaceholder.typicode.com/posts', {
        method: 'POST',
        headers: {
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(data)
    })
    let dataResponse = await response.json()
    console.log(dataResponse)
}

//getUsers()
insertPost({
    name: 'Jean',
    age: 29
})