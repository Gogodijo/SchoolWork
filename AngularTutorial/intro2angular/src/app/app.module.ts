import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';
import { FormsModule } from '@angular/forms';
import { RouterModule} from '@angular/router'

import { AppComponent } from './app.component';
import { HelloComponent } from './hello/hello.component';
import { RecordsService} from './records.service';
import { HttpClientModule } from '@angular/common/http';
import { HomeComponent } from './home/home.component';
import { DataComponent } from './data/data.component';
import { LoginComponent } from './login/login.component';
import { AuthGuard} from './auth.guard'
import { UserService } from './user.service';
import { LogoutComponent } from './logout/logout.component'
import { DashboardComponent } from './dashboard/dashboard.component';
import { RegisterComponent } from './register/register.component';
@NgModule({
  declarations: [
    AppComponent,
    HelloComponent,
    HomeComponent,
    DataComponent,
    LoginComponent,
    LogoutComponent,
    DashboardComponent,
    RegisterComponent
  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpClientModule,
    RouterModule.forRoot([ 
      {
        path: '',
        component: HomeComponent
      },
      {
        path: 'logout',
        component: LogoutComponent
      },
      {
        path:'login',
        component: LoginComponent
      },
      {
        path:'dashboard',
        component: DashboardComponent,
        canActivate: [AuthGuard]
      },
      {
        path :'register',
        component: RegisterComponent
      }
    ])
  ],
  providers: [RecordsService, AuthGuard, UserService],
  bootstrap: [AppComponent]
})
export class AppModule { }
