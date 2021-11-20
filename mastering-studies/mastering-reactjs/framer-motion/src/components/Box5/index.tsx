import React, { useState } from "react";
import { motion, useAnimation } from "framer-motion";

export default function Box5() {
  const { div } = motion
  const [isAnimating, setIsAnimating] = useState<boolean>(false);
  const control = useAnimation()
  return (
    <div className="box-container">
      <button onClick={() => {
        control.start({
          x: "70vw",
          transition: {
            duration: 2
          }
        })
      }}>Move right</button>
      <button onClick={() => {
        control.start({
          x: 0,
          transition: {
            duration: 2
          }
        })
      }}>Move left</button>
      <button>Circle</button>
      <button>Square</button>
      <button>Stop</button>
      <motion.div animate={control} className="box"></motion.div>
    </div>
  );
}

//https://www.youtube.com/watch?v=1vKiPwEYbyk 31:00
