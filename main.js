// const WebSocketServer = require('ws');
// const screenshot = require('screenshot-desktop')
// const wss = new WebSocketServer.Server({ port: 8080 })
const cors = require('cors')
const express = require("express")
const app = express()
app.use(cors())
app.use(express.urlencoded({extended:true}))

// function takeScreenShot(client){

// }

// wss.on("connection", ws => {
//     ws.id=Number(Math.random()*20)
//     console.log(`New client connected id:${ws.id}`);

//     console.log(`All clients`);
//     wss.clients.forEach(e=>console.log(e.id))

//     ws.on("message", data => {
//         console.log(`Client has sent us: ${data}`)
//     });
 

//     ws.on("close", () => {
//         console.log("the client has disconnected");
        
//     });
  
    
//     ws.onerror = function () {
//         console.log("Some Error occurred")
//     }
// });
// console.log("The WebSocket server is running on port 8080");


console.log("------------------ ");
app.use(express.json())

app.get("/app",(req,res)=>{

    console.log(req.url)
    // screenshot({filename:'screenshot.png'})
    res.send("recived")
})
app.listen(1234,()=>console.log("Express server stared at port 1234"))