import express from 'express'

const app = express()

app.listen(3333, () => {
    console.log('listening in the port 3333');
    
})


export default app;