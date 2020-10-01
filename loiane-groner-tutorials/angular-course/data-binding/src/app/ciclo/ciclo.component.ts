import { Input, AfterContentChecked, AfterContentInit, AfterViewChecked, AfterViewInit, Component, DoCheck, OnChanges, OnDestroy, OnInit } from '@angular/core';

@Component({
  selector: 'app-ciclo',
  templateUrl: './ciclo.component.html',
  styleUrls: ['./ciclo.component.css']
})
export class CicloComponent implements OnInit,
OnChanges, DoCheck, AfterContentInit, AfterContentChecked,
AfterViewInit, AfterViewChecked, OnDestroy{

 @Input() valorInicial: number = 10

  constructor() {
    this.log('construct')
  }
  ngOnChanges() {
    this.log('ngOnChanges')
  }
  ngOnInit() {
   this.log('ngOnInit')
  }
   ngAfterContentInit() {
    this.log('ngAfterContentInit')
   }
   ngAfterContentChecked() {
     this.log('ngAfterContentChecked')
   }
   ngAfterViewInit() {
     this.log('ngAfterViewInit')
   }
   ngAfterViewChecked() {
     this.log('ngAfterViewChecked')
   }
   ngDoCheck() {
     this.log('ngDoCheck')
   }
   ngOnDestroy() {
     this.log('ngOnDestroy')
   }

  private log(hook: string) {
    console.log(hook)
  }
}
