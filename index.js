const express = require('express')
const app= express()

app.get("/",(req,res)=>{
    res.json({hai:"hello"})
})

app.listen(80,()=>console.log("Application started"))