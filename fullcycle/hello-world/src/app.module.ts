import { Module } from '@nestjs/common';
import { AppController } from './app.controller';
import { AppService } from './app.service';
import { TesteController } from './teste/teste.controller';

@Module({
  imports: [],
  controllers: [AppController, TesteController],
  providers: [AppService],
})
export class AppModule {}
