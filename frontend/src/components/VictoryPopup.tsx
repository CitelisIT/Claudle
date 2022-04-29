import React, { useContext } from "react";
import { Dialog } from "@headlessui/react";
import { XIcon } from "@heroicons/react/outline";
import { SettingsContext } from "../App";

interface Props {
  gameWon: boolean;
  setGameWon: React.Dispatch<React.SetStateAction<boolean>>;
  target: string;
  resetGame: () => void;
}

function DefinitionLink(props: any) {
  const settingsContext = useContext(SettingsContext);
  const lang =
    settingsContext.lang === "english" ? "en" : "francais" ? "fr" : "cloclo";
  return (
    <button
      className="p-2 mt-12 mr-8 text-sm border rounded-lg text-amber-400 border-amber-400 w-max md:text-lg lg:text-xl"
      onClick={() =>
        window.open(
          lang === "fr"
            ? "https://www.cnrtl.fr/definition/" + props.target
            : "https://dictionary.cambridge.org/dictionary/english/" +
                props.target,
          "_blank"
        )
      }
    >
      Définition
    </button>
  );
}

export default function VictoryPopup({
  gameWon,
  setGameWon,
  target,
  resetGame,
}: Props) {
  const settingsContext = useContext(SettingsContext);
  return (
    <Dialog
      open={gameWon}
      onClose={() => setGameWon(false)}
      className="fixed inset-0 w-10/12 p-4 m-auto text-gray-200 bg-gray-900 border border-gray-600 rounded-lg shadow-2xl mg:p-8 lg:w-5/12 mx-1/2 h-fit"
    >
      <Dialog.Overlay />
      <button
        onClick={() => {
          setGameWon(false);
        }}
        className="absolute top-0 right-0 p-4 "
      >
        <XIcon className="w-6 h-6 text-gray-200 md:w-8 md:h-8" />
      </button>
      <div className="flex flex-col justify-center w-full gap-4 p-6 md:gap-12 md:p-16 flex-center">
        <Dialog.Title className="mx-24 text-lg font-semibold text-center text-gray-200 md:text-3xl ">
          <div className="flex items-center justify-center w-full">
            <span> Vous avez gagné </span>
            <img
              src="./ClaudeFrancoisJoie.jpg"
              className="w-6 h-6 ml-6 text-gray-200 md:w-20 md:h-20"
            />
          </div>
        </Dialog.Title>

        <Dialog.Description as="div" className="w-full">
          <div className="flex items-center justify-center">
            {settingsContext.lang === "english" ? (
              <DefinitionLink target={target} />
            ) : settingsContext.lang === "francais" ? (
              <DefinitionLink target={target} />
            ) : (
              <div></div>
            )}
            <button
              onClick={() => {
                setGameWon(false);
                settingsContext.setGameState(0);
                resetGame();
              }}
              className="p-2 mt-12 mr-8 text-sm text-green-600 border border-green-600 rounded-lg w-max md:text-lg lg:text-xl"
            >
              Nouvelle partie
            </button>
          </div>
          <p className="flex flex-col items-center justify-center w-full p-3 mt-1 text-sm text-gray-600">
            ou appuyez sur entrée pour rejouer
          </p>
        </Dialog.Description>
      </div>
    </Dialog>
  );
}
