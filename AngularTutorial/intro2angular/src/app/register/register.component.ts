import { Component, OnInit } from '@angular/core';
import { AuthService } from '../auth.service';
import { Router } from '@angular/router';



@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.scss']
})


export class RegisterComponent implements OnInit {

  constructor(private auth : AuthService, private router: Router) { }

  ngOnInit() {
  }

  registerUser(event){
    event.preventDefault()
    const target = event.target
    const errors = []
    const username:string = target.querySelector('#username').value.trim()
    const password = target.querySelector('#password').value
    const cpassword = target.querySelector('#cpassword').value

    if(username === ""){
      console.log("Username should not be empty")
      errors.push("Username should not be empty")

    }

    if(password !== cpassword) {
      console.log("Passwords did not match")
      errors.push("Passwords do not match!")
    }

    if(errors.length > 0){
      window.alert(errors)
    }
    else{
      this.auth.registerUser(username,password).subscribe(data => {
        console.log(data)
        if(data.success) {
          this.router.navigate(['dashboard'])
        }else{
          window.alert(data.message)
        }
      })
    }
    }

}
