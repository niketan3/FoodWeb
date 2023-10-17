const mongoose = require('mongoose')

const { Schema } = mongoose;

const UserSchema = new Schema({
    CategoryName:{
        type:String,
       
    },
    name:{
        type:String,
 
    },
    img:{
        type:String,
        
    },
    options:{
        type:JSON,
    },
    description:{
        type:String,
    },

  });

  module.exports = mongoose.model('data',UserSchema)