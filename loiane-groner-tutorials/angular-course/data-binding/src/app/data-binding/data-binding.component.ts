import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-data-binding',
  templateUrl: './data-binding.component.html',
  styleUrls: ['./data-binding.component.css']
})
export class DataBindingComponent implements OnInit {

  url: string = 'http://loiane.com'

  angularCourse: boolean = true

  urlImage: string = 'http://lorempixel.com/g/400/200/nature/'

  actualValue: string = ''

  savedValue: any

  isMouseOver: boolean = false

  saveValue(value) {
    this.savedValue = value
  }

  getValue() {
    return 1
  }

  getLikeCourses() {
    return true
  }

  clickedButton() {
    alert('clicked button')
  }
  onKeyUp(event: KeyboardEvent) {
    this.actualValue = (<HTMLInputElement>event.target).value
  }

  onMouseOverOut() {
    this.isMouseOver = !this.isMouseOver
  }

  constructor() { }

  ngOnInit() {
  }

}
