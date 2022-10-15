const WebSocketServer = require('ws');
const fs=require('fs')

const wss = new WebSocketServer.Server({ port: 8080 })

wss.on("connection", ws => {
    
    console.log(`All clients`);
    wss.clients.forEach(e=>console.log(e.id))
    ws.on("message", data => {
        if(!ws.auth){
              ws.id= JSON.parse(data).id
              console.log(`Client with id: ${ws.id}`)
              ws.auth=true
        }
        else {
            console.log(`data recived from ${ws.id}`)

            fs.writeFile(`./ss/ss${ws.id}.png`,data,(err)=>{
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



//--------------------server to get the requests

const express = require("express")
const cors = require('cors')

const app = express()

app.use(cors())
app.use(express.json())
app.use(express.urlencoded({extended:true}))
app.use(express.static("ss"))


app.post("/ss",(req,res)=>{
    const id=req.body.id
    console.log(req.body)
    for(var client of wss.clients){
        if(client.id==id){
            new Promise((resolve,reject)=>{
                    client.recived=resolve
                    client.failed=reject
                    client.send("ss")
            }).then(r=>{
                res.json({status:true,id:client.id})
            }).catch(err=>{
                res.json({status:false})
            })
            break
        }
    }
})
app.listen(1234,()=>console.log("Express server stared at port 1234"))