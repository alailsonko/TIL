import React, { useState } from "react";
import { motion, AnimationProps, Variant } from "framer-motion";

export default function Box3() {
  const [isAnimating, setIsAnimating] = useState<boolean>(false);
  // const boxVariant: AnimationProps["variants"] = {
  //   lion: {
  //     x: 100,
  //     scale: 1.5,
  //     backgroundColor: "yellow",
  //   } as Variant,
  //   elephant: {
  //     x: 1000,
  //     scale: 0.3,
  //     backgroundColor: "green"
  //   } as Variant,
  // };
  const boxVariant = {
    hidden: {
      x: "-100vw",
    },
    visible: {
      x: 0,
      transition: {
        delay: 0.2,
        when: "beforeChildren"
      },
    } as Variant,
  };

  const listVariant = {
    hidden: {
      x: -10,
      opacity: 0,
    },
    visible: {
      x: 0,
      opacity: 1,
      transition: {
        type: "spring",
        stiffness: 20,
      },
    } as Variant,
  };

  return (
    <div className="box-container">
      <motion.div
        className="box"
        // variants={boxVariant}
        // animate="elephant"
        variants={boxVariant}
        animate="visible"
        initial="hidden"
      >
        {[1, 2, 3].map((box) => {
          return (
            <motion.li
              variants={listVariant}
              animate="visible"
              initial="hidden"
              className="boxItem"
            ></motion.li>
          );
        })}
      </motion.div>
    </div>
  );
}

//https://www.youtube.com/watch?v=1vKiPwEYbyk 31:00
