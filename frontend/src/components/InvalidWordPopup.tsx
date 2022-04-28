import { Dialog } from "@headlessui/react";

interface Props {
  badWord: boolean;
  setBadWord: React.Dispatch<React.SetStateAction<boolean>>;
}

export default function InvalidWordPopup({ badWord, setBadWord }: Props) {
  return (
    <Dialog open={badWord} onClose={() => setBadWord(false)}>
      <Dialog.Title className="fixed flex items-center justify-center p-1 m-auto bg-gray-700 border border-gray-800 rounded-lg top-20 left-4 right-4 md:w-3/12">
        <h3 className="items-center text-base font-semibold text-gray-200 md:text-lg lg:text-xl">
          Mot invalide
        </h3>
      </Dialog.Title>
    </Dialog>
  );
}
