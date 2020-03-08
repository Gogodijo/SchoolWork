import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders} from '@angular/common/http'
import { Observable } from 'rxjs';

interface myData {
  success: boolean,
  message: string
}
interface registerUserInterface{
  success: boolean,
  message : string
}

@Injectable({
  providedIn: 'root'
})
export class AuthService {
  private loggedInStatus = false

  setLoggedIn(arg0: boolean) {
    this.loggedInStatus = arg0
  }
  get isLoggedIn(){
    return this.loggedInStatus
    
  }
  constructor(private http : HttpClient) { }
  getUserDetails(username: string, password: string){
    //post these details to API server, return user info if correct

   let postBody = {
      'email' : username,
      'password' : password
    }
    return this.http.post<myData>('/api/login',postBody, 
    {headers: new HttpHeaders().set('Content-Type', 'application/json')
      })
  }

  registerUser(username: string,password :string){
    return this.http.post<registerUserInterface>('api/register',{
     'email' : username,
      'password' : password
    },{headers: new HttpHeaders().set('Content-Type', 'application/json')
  } )
  }
}
