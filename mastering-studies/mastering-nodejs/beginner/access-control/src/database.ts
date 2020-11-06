import mongoose from 'mongoose'
import appConfig from './config'

const config = appConfig as { secret: string, database: any                              }

export const databaseConnect =  ( async() => {
    return await mongoose.connect(config.database, { useUnifiedTopology: true ,useNewUrlParser: true })
           .then(() => console.log('mongodb is connected'))
           .catch(err => console.log('something went wrong ',err))
})