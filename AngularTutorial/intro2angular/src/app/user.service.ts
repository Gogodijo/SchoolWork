import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { AuthService } from './auth.service';

interface myData {
  "status": boolean,
  "email": string,
  "quote": string
}
interface isLoggedIn {
  "status": boolean
}
interface logout {
  "success" : boolean
}
interface updateQuote{
  "status" : boolean
}

@Injectable({
  providedIn: 'root'
})
export class UserService {

  constructor(private http: HttpClient, private auth: AuthService) { }

  getData(){

    return this.http.get<myData>('api/data')
  }


  isLoggedIn() {
    return this.http.get<isLoggedIn>('api/isLoggedin')
  }

  logout(){
    this.auth.setLoggedIn(false)
    return this.http.get<logout>('api/logout',)
    
  }

  updateQuote(quote){

    return this.http.post<updateQuote>('api/updateQuote',{'quote': quote})
  }
}
