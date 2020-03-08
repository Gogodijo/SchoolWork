import { Component, OnInit } from '@angular/core';
import { AuthService } from '../auth.service';
import { Router } from '@angular/router';


@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.scss']
})
export class LoginComponent implements OnInit {


  constructor(private auth: AuthService, private router: Router) { }

  ngOnInit() {
  }

  loginUser(event){
    event.preventDefault()
    const target = event.target
    const username = target.querySelector('#username').value
    const password = target.querySelector('#password').value

    this.auth.getUserDetails(username,password).subscribe(data => {
      if(data.success) {
        this.router.navigate(['dashboard'])
        this.auth.setLoggedIn(true)
      }
      else{
       // console.log(data.success,data.message)
        window.alert(data.message)
      }
    })

  }

}
