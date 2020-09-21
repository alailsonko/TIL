import { Controller, Get } from '@nestjs/common';
import {AppService} from '../app.service'

@Controller('teste')
export class TesteController {
    constructor(private appService: AppService) {

    }

    @Get('Hello-world')
    index(): string{
      return this.appService.getHello() + 'alailson';
    }
}
