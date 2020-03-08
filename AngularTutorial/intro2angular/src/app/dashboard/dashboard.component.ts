import { Component, OnInit } from '@angular/core';
import { UserService } from '../user.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-dashboard',
  templateUrl: './dashboard.component.html',
  styleUrls: ['./dashboard.component.scss']
})
export class DashboardComponent implements OnInit {

  message = "Loading your personal quote"
  email = "Getting your email"

  constructor(private user: UserService, private router: Router) { }

  ngOnInit() {
    this.user.getData().subscribe(data => {
      if(data.status){
        this.message = data.quote
        this.email = data.email
      }else{
        this.router.navigate(['logout'])
      }
    })
  }

  updateQuote(event){
    event.preventDefault()
    const value = event.target.parentNode.querySelector('#myQuote').value
    console.log(value)
    this.user.updateQuote(value).subscribe(data =>{
      if(data.status){

      }else{
        
      }
    })
  }

}
