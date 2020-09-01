import {
  Column, Entity, PrimaryGeneratedColumn,
} from 'typeorm';

@Entity('Class')
export default class Class {
  @PrimaryGeneratedColumn('uuid')
  id: string;

  @Column({
    length: 100,
    unique: true,
  })
  name: string;

  @Column()
  duration: number;

  @Column()
  createdAt: Date;

  @Column()
  updatedAt: Date;
}
