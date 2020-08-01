import express from 'express'

const routes = express.Router()

routes.get('/', (req, res) => {
    return res.json({ message: 'Hello world' })
})

routes.post('/posts', (req, res) => {
    return res.json({ message: 'New post' })
})

export default routes;