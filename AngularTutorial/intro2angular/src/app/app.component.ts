import { Component } from '@angular/core';
import { HelloComponent } from './hello/hello.component';
import { RecordsService } from './records.service';


interface myData {
  obj: Object
}

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  
  constructor() {
  
  }

  ngOnInit(){
   
  }
}
