import express, { Request, Response } from 'express';
import { databaseConnect } from './database'

const app = express();

databaseConnect()

app.get('/', (req, res) => {
    return res.send('it wors')
})

const port = process.env.PORT || 3333
app.listen(port, () => {
    console.log('listening on port', `${port}`)
})

export default app