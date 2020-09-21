import { Test, TestingModule } from '@nestjs/testing';
import { TesteController } from './teste.controller';

describe('Teste Controller', () => {
  let controller: TesteController;

  beforeEach(async () => {
    const module: TestingModule = await Test.createTestingModule({
      controllers: [TesteController],
    }).compile();

    controller = module.get<TesteController>(TesteController);
  });

  it('should be defined', () => {
    expect(controller).toBeDefined();
  });
});
