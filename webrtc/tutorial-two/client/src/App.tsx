import React, { useEffect, useState } from "react";
import { format } from "date-fns";

import { io, Socket } from "socket.io-client";

function App() {
  const [timer, setTimer] = useState<string>(new Date().toDateString());
  const [socket, setSocket] = useState<Socket>(io("http://localhost:3005"));

  useEffect(() => {
    const newSocket = io("http://localhost:3005");
    setSocket(newSocket);
    return () => {
      newSocket.close();
    };
  }, [setSocket]);

  useEffect(() => {
      socket!.on("timer", (arg1: React.SetStateAction<string>) => {
        console.log("timer", arg1);
        setTimer(arg1);
        console.log(socket);
        console.log(socket.id);
      });
  }, [socket, timer]);

  return <div className="App">{format(new Date(timer!), "HH:mm:ss")}</div>;
}

export default App;
