const WebSocketServer = require('ws');
const fs=require('fs')

const wss = new WebSocketServer.Server({ port: 8080 })

wss.on("connection", ws => {
    
    console.log(`All clients`);
    wss.clients.forEach(e=>console.log(e.token))
    ws.on("message", data => {
        if(!ws.auth){
              ws.token= JSON.parse(data).token
              console.log(`Client with token: ${ws.token}`)
              ws.auth=true
        }
        else {
            console.log(`data recived from ${ws.token}`)
            ws.file=`ss${ws.token}${Date.now()}.png`
            fs.writeFile(`./ss/${ws.file}`,data,(err)=>{
                if(err) ws.failed()
                else ws.recived()
            })

        }
    });
    ws.on("close", () => {
        console.log("the client has disconnected");
        
    });
    ws.onerror = function () {
        console.log("Some Error occurred")
    }
});
console.log("The WebSocket server is running on port 8080");



//---------------  server to get the requests

const express = require("express")
const cors = require('cors')

const app = express()

app.use(cors())
app.use(express.json())
app.use(express.urlencoded({extended:true}))
app.use(express.static("ss"))


app.post("/ss",(req,res)=>{
    const token=req.body.token
    console.log(req.body)
    var clientConnected=false
    for(var client of wss.clients){
        if(client.token==token){
            clientConnected=true
            new Promise((resolve,reject)=>{
                    client.recived=resolve
                    client.failed=reject
                    client.send("ss")
            }).then(r=>{
                res.json({status:true,file:`${client.file}`})
            }).catch(err=>{
                res.json({status:false})
            })
            break
        }
    }
    if(!clientConnected) res.json({status:false,not_online:true})
})
app.get("/",(req,res)=>{
    res.send("<h1>Hello world</h1>")
})
app.listen(1333,()=>console.log("Express server stared at port 1333"))