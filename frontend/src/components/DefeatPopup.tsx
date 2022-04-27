import React, { useContext } from "react";
import { Dialog } from "@headlessui/react";
import { XIcon } from "@heroicons/react/outline";
import { SettingsContext } from "../App";

interface Props {
  gameLost: boolean;
  setGameLost: React.Dispatch<React.SetStateAction<boolean>>;
  target: string;
  resetGame: () => void;
}

export default function DefeatPopup({
  gameLost,
  setGameLost,
  target,
  resetGame,
}: Props) {
  const settingsContext = useContext(SettingsContext);
  return (
    <Dialog
      open={gameLost}
      onClose={() => setGameLost(false)}
      className="fixed inset-0 w-10/12 p-4 m-auto text-gray-200 bg-gray-900 border border-gray-600 rounded-lg shadow-2xl mg:p-8 lg:w-5/12 mx-1/2 h-fit"
    >
      <Dialog.Overlay />
      <button
        onClick={() => {
          setGameLost(false);
        }}
        className="absolute top-0 right-0 p-4 "
      >
        <XIcon className="w-6 h-6 text-gray-200 md:w-8 md:h-8" />
      </button>
      <div className="flex flex-col justify-center w-full gap-4 p-6 md:gap-12 md:p-16 flex-center">
        <Dialog.Title className="mx-24 text-lg font-semibold text-center text-gray-200 md:text-3xl ">
          <div className="flex items-center justify-center w-full">
            <span> Vous avez perdu =( </span>
          </div>
        </Dialog.Title>
        <Dialog.Description as="div" className="w-full">
          <div className="flex flex-col items-center justify-center w-full gap-4 p-2 md:gap-12 md:text-xl">
            <span> Le mot cherché etait : {target} </span>
            <button
              onClick={() => {
                setGameLost(false);
                settingsContext.setGameState(0);
                resetGame();
              }}
              className="p-2 mt-12 text-sm text-green-600 border border-green-600 rounded-lg w-max md:text-lg lg:text-xl"
            >
              Nouvelle partie
            </button>
          </div>
        </Dialog.Description>
      </div>
    </Dialog>
  );
}
