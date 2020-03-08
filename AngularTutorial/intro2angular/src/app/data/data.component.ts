import { Component, OnInit } from '@angular/core';
import { RecordsService } from '../records.service';

@Component({
  selector: 'app-data',
  templateUrl: './data.component.html',
  styleUrls: ['./data.component.scss']
})
export class DataComponent implements OnInit {

  records:any = []
  constructor(private myFirstService : RecordsService) {
  
  }

  ngOnInit(){
    this.myFirstService.getData().subscribe(data =>{
      console.log("We got Data!" , data)
      this.records = data
    })
  }

}
