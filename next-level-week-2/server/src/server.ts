import express from 'express'

const app = express()

app.get('/users', (req, res) => {

    const users = [
        {name: 'John', age: 36},
        {name: 'Anna', age: 16},
    ]

   return res.json(users)
})

app.listen(3333, () => {
    console.log("listening on port 3333")
})
