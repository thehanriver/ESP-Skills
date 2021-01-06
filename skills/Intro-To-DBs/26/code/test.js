// Modules
//var level = require('level')
var express = require('express');
var app = require('express')();
var http = require('http').Server(app);
var io = require('socket.io')(http);
var mongo = require('mongodb');
// Create or open the underlying LevelDB store
//var db = level('./mydb', {valueEncoding: 'json'});
const MongoClient = require('mongodb').MongoClient;
const uri = "mongodb+srv://mario:1GBSt0rage%21@vivcluster.h5rba.mongodb.net/testSmok?retryWrites=true&w=majority";
// const client = new MongoClient(uri, { useNewUrlParser: true });
// client.connect(err => {
//   const collection = client.db("test").collection("devices");
//   // perform actions on the collection object
//   client.close();
// });
// const MongoClient = require('mongodb').MongoClient;
// const uri = "mongodb+srv://mario:1GBSt0rage%21@cluster0.zottf.mongodb.net/VivCluster?retryWrites=true&w=majority";
const client = new MongoClient(uri, {useUnifiedTopology: true, useNewUrlParser: true});
const fs = require('fs');

client.connect((err,db) => {
if(err) throw err;
var dbo = db.db("skill26b");
var myobj = [];
fs.readFile('./smoke.txt',(err,data) => {
  if(err) throw err;
  var lines = data.toString().split(/\r?\n/);
  lines.map(function(item){
    var tabs = item.split('\t');
    if(tabs[0] == 'Time') return;
    myobj.push({time: tabs[0], id: parseInt(tabs[1]), smoke: parseInt(tabs[2]), temp: parseInt(tabs[3])});
    console.log({time: tabs[0], id: tabs[1], smoke: tabs[2], temp:[3]});
  });
    dbo.collection("smoke").insertMany(myobj,function(err, res){
    if(err) throw err;
    console.log("Number of documents inserts: " + res.insertedCount);
    db.close();
    });
  });
});

// // Do every 1500 ms
// setInterval(intervalFunc, 1500);
