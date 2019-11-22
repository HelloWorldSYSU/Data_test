var http = require('http')
var querystring = require('querystring')
var url = require('url')
var MongoClient = require('mongodb').MongoClient
var DB_PATH = 'mongodb://localhost:27017/'


var server = http.createServer(function (req, res) {
	var path = url.parse(req.url).pathname
	console.log(path)
	console.log("received")	
	if(path == "/register" && req.method === 'POST'){
		var data = ''
		console.log('Good')
		req.on('data', function (chunk) {
			data += chunk
		})

		req.on('end', function () {
			var dataObject = JSON.parse(data);
			console.log(dataObject[1][1]);
		})
	}

})

server.listen(80, "0.0.0.0")
console.log("running");

var insertData = function(db, callback){

         var collection = db.collection('userInfo')

         var data = [{"name":"sysumach","age":19},{"name":"kaijie","age":19}];
         collection.insert(data, function(err, result){
                if(err)
                {
                        console.log('Error:' + err)
                        return
                }
                callback(result)
        });
}

MongoClient.connect(DB_PATH, function(err, db){
        var dbo = db.db('admin')
      console.log("connnect successfully!")
         insertData(dbo, function(result){
                 console.log(result)
                 db.close()
         })
