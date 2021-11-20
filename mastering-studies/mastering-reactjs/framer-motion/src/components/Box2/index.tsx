import React, { useState } from "react";
import { motion } from "framer-motion";

export default function Box2() {
  const [isAnimating, setIsAnimating] = useState<boolean>(false);
  return (
    <div className="box-container">
      <motion.div
        className="box"
        drag
        dragConstraints={{
          right: 20,
          left: -20,
          top: 5,
          bottom: 10,
        }}
        whileHover={{
          scale: 1.1
        }}
        whileTap={{
          scale: 0.9
        }}
        // onClick={() => setIsAnimating(!isAnimating)}
      ></motion.div>
    </div>
  );
}

//https://www.youtube.com/watch?v=1vKiPwEYbyk 31:00