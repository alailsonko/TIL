import express, { Express } from 'express'
import { createServer } from "http";
import { Server } from 'socket.io'


const app: Express = express()
const httpServer = createServer(app);
const io = new Server(httpServer, {
    cors: {
        origin: '*',
    }
})

io.on("connection", (socket) => {
    socket.data.username = "alice";
});

httpServer.listen(3000)