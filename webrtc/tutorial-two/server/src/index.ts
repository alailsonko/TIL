import express, { Express } from 'express'
import { createServer } from "http";
import { Server, Socket } from 'socket.io'


const app: Express = express()

app.get('/', (req, res) => {
    res.send('Hello World!')
})

const httpServer = createServer(app);
const io = new Server(httpServer, {
    cors: {
        origin: '*',
    }
})

setInterval(() => {
    io.on("connection", (socket) => {
        socket.emit("timer", new Date());
        socket.disconnect()
    });
}, 1000)



httpServer.listen(3005, () => {
    console.log('listening on port http://localhost:3005')
})