const express = require('express')

const app = express()

const port = 3333
/**
 * metthods HTTP
 * GET: seek information from backend
 * POST: create one information in the backend
 * PUT/PATCH: change uma information no backend
 * DELETE: delete one information in the backend
 */


app.get('/projects', (req, res) => {
    return res.send({message: "hello wold"})
})

app.listen(port, () => {
    console.log(`backend started at port ${port}`);
})