const express = require('express')
const bodyParser = require('body-parser')
const app = express();
const cookieParser = require('cookie-parser')
const session = require('express-session')
const mongoose = require('mongoose')

mongoose.Promise = Promise
mongoose.connect('mongodb://127.0.0.1:27017/angulardb').then(() => {
  console.log("Mongoose up!")
})

const User = require('./schemas/users')

app.use(cookieParser());
app.use(session({
  secret: "Shh, its a secret!",
  //saveUninitialized: false,
  resave: false
}));
app.use(bodyParser.json())


app.get('/data', async (req, res) => {

  const user = await User.findOne({ email: req.session.user })
  if (!user) {
    res.json({
      status: false,
    })
    return
  }

  res.json({
    status: true,
    email: req.session.user,
    quote: user.quote
  })
});

app.post('/login', async (req, res) => {
  const { email, password } = req.body
  const resp = await User.findOne({ email, password })
  if (!resp) {
    console.log("Incorrect details")
    res.send({
      "success": false,
      "message": "Incorrect details"
    })

  } else {
    //Make a session. set user to logged in
    req.session.user = email
    console.log("Logging you in")
    res.send({
      "success": true,
      "message": "Logging you in"
    })
  }
})

app.listen(3000, () => {
  console.log('Starting backend on port 3000')
});

app.get('/isLoggedin', (req, res) => {
  console.log(req.session.user)
  res.json({
    status: !!req.session.user
  })
}
)

app.get('/logout', (req, res) => {
  req.session.destroy()
  res.send({
    "success": true
  })

})

app.post('/register', async (req, res) => {
  const { email, password } = req.body
  const user = new User({
    email,
    password
  })
  console.log(user)
  const resp = await User.findOne({ email: email })
  console.log(resp)
  if (resp) {
    console.log("Username already taken.")
    res.send({
      "success": false,
      "message": "Username already taken"
    })
    return
  } else {
    const result = await user.save()
    if (result) {
      res.send({
        "success": true,
        "message": "Register completed"
      })
    }
    else {
      res.send({
        "success": false,
        "message": "Unknown error, please try again"
      })
    }
  }
})


app.post('/updateQuote', async (req, res) => {
  const quote = req.body.quote
  const query = { email: req.session.user }
  await User.updateOne(query, { quote: quote })
    res.json({
      status: true
    })
})

